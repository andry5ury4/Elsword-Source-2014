﻿ALTER TABLE [dbo].[WIUser] ADD
CONSTRAINT [FK_WIUser_WIIssue] FOREIGN KEY ([IssueUID]) REFERENCES [dbo].[WIIssue] ([IssueUID]) ON DELETE CASCADE ON UPDATE CASCADE


