﻿ALTER TABLE [dbo].[ESantaLimitDate] ADD
CONSTRAINT [FK_ESantaLimitDate_ESantaEventUID] FOREIGN KEY ([EventUID]) REFERENCES [dbo].[ESantaEventUID] ([EventUID]) ON DELETE CASCADE ON UPDATE CASCADE


