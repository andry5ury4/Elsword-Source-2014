﻿ALTER TABLE [dbo].[ECEventChatWord] ADD
CONSTRAINT [FK_ECEventChatWord_ECEventChatDate] FOREIGN KEY ([UID]) REFERENCES [dbo].[ECEventChatDate] ([UID]) ON DELETE CASCADE ON UPDATE CASCADE


