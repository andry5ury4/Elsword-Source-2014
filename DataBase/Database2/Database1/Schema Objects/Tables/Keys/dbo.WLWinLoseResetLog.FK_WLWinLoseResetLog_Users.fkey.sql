﻿ALTER TABLE [dbo].[WLWinLoseResetLog] ADD
CONSTRAINT [FK_WLWinLoseResetLog_Users] FOREIGN KEY ([LoginUID]) REFERENCES [dbo].[users] ([LoginUID]) ON DELETE CASCADE ON UPDATE CASCADE


