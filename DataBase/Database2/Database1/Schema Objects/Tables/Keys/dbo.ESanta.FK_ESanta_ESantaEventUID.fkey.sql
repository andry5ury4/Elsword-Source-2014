﻿ALTER TABLE [dbo].[ESanta] ADD
CONSTRAINT [FK_ESanta_ESantaEventUID] FOREIGN KEY ([EventUID]) REFERENCES [dbo].[ESantaEventUID] ([EventUID]) ON DELETE CASCADE ON UPDATE CASCADE


