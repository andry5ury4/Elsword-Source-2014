﻿ALTER TABLE [dbo].[GResurrectionStone] ADD
CONSTRAINT [FK_GResurrectionStone_GUnit] FOREIGN KEY ([UnitUID]) REFERENCES [dbo].[GUnit] ([UnitUID]) ON DELETE CASCADE ON UPDATE CASCADE


