﻿/*	sutamtwo
	OK값

	-1 : 삭제 에러
	-2 : 삭제 기록 작성 에러
*/
CREATE PROCEDURE [dbo].[gup_get_tool_delete_quests]
	@iQuestID_	[bigint]
,	@iUnitUID_	[bigint]
,	@strID_		[nvarchar](20)
,	@strIP_		[nvarchar](15)
,	@iOK		[int] = 0


AS
SET NOCOUNT ON;

BEGIN TRAN
	
	delete from game01.dbo.GQuests
		where unitUID = @iUnitUID_ and questID = @iQuestID_

    IF @@ERROR <> 0 OR @@ROWCOUNT <> 1
        BEGIN    SELECT @iOK = -1    GOTO FAIL_TRAN    END

	insert into account.dbo.DeleteQuests (UnitUID, QuestID, Session, IP)
		select @iUnitUID_, @iQuestID_, @strID_,@strIP_

    IF @@ERROR <> 0 OR @@ROWCOUNT <> 1
        BEGIN    SELECT @iOK = -2    GOTO FAIL_TRAN    END


COMMIT TRAN


GOTO END_PROC

FAIL_TRAN:
ROLLBACK TRAN

END_PROC:
SELECT @iOK


