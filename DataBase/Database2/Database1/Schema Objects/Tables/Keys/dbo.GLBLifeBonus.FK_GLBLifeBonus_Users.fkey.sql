﻿ALTER TABLE [dbo].[GLBLifeBonus] ADD
CONSTRAINT [FK_GLBLifeBonus_Users] FOREIGN KEY ([LoginUID]) REFERENCES [dbo].[users] ([LoginUID]) ON DELETE CASCADE ON UPDATE CASCADE

