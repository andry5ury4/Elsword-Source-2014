﻿CREATE PROCEDURE [dbo].[EPDB_event_perfect_mode_insert]
	@iEventUID_ [int],
	@iMode_ [int],
	@iType_ [int],
	@iOK [int] = 0
AS
set nocount on
set transaction isolation level read uncommitted

/*
    mk8253.이벤트 캐릭터 추가
*/

if not exists
(
    SELECT *
	FROM dbo.EPGAEventPerfect
	WITH (nolock)
	WHERE EventUID = @iEventUID_
)
begin select @iOK = -1 goto end_proc end

begin transaction
    INSERT INTO dbo.EPGAEventPerfectMode
    with (updlock)
    (
	    EventUID
    ,   ModeID
    ,   Type
    )
    select
        @iEventUID_
    ,   @iMode_
    ,   @iType_
        
    if @@error <> 0
    begin select @iOK = -101 goto fail_tran end
commit transaction

goto end_proc

fail_tran:
    rollback transaction

end_proc:
    select @iOK as OK


