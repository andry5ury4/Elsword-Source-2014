﻿CREATE PROCEDURE [dbo].[CSGA_couple_system_delete_warehouse]
	@iLoginUID_ [int],
	@iItemUID_ [int],
	@iItemID_ [int],
	@iOK [int] = 0
AS
set nocount on
set transaction isolation level read uncommitted

/*
20081113. microcat.

{ call dbo.CSGA_couple_system_delete_warehouse ( %d, %d, %d ) }

{ call dbo.CSGA_couple_system_delete_warehouse ( @1, @2, @3 ) }
@1 ; LoginUID int ; 내꺼
@2 ; ItemUID int
@3 ; itemID int

1 return ( @1 )
@1 ; OK int

OK
0 ; 성공
-1 ; 내꺼 유저 정보가 존재하지 않음
-2 ; 내 커플 정보가 존재하지 않음
-3 ; 내 창고 정보가 존재하지 않음
-101이하 ; 트랜잭션 에러
*/

execute dbo.AAA_login_check
    @iLoginUID_
,   @iOK output

if @iOK <> 0
begin    select @iOK = -1    goto end_proc    end

if not exists
(
    select *
    from dbo.CSGACoupleSystem
    where
        LoginUID = @iLoginUID_
)
begin    select @iOK = -2    goto end_proc    end

if not exists
(
    select *
    from dbo.CSGACoupleSystemWarehouse
    where
        LoginUID = @iLoginUID_
    and ItemUID = @iItemUID_
    and ItemID = @iItemID_
)
begin    select @iOK = -3    goto end_proc    end


begin transaction

delete a
with (updlock)
from dbo.CSGACoupleSystemWarehouse
as a
with (updlock)
where
    LoginUID = @iLoginUID_
and ItemUID = @iItemUID_
and ItemID = @iItemID_
option (maxdop 1)

if @@error <> 0
begin    select @iOK = -101    goto fail_tran    end

commit transaction

goto end_proc

fail_tran:
rollback transaction

end_proc:
select
    @iOK


