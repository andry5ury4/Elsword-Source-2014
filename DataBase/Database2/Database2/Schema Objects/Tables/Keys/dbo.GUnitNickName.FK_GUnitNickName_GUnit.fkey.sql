﻿ALTER TABLE [dbo].[GUnitNickName] ADD
CONSTRAINT [FK_GUnitNickName_GUnit] FOREIGN KEY ([UnitUID]) REFERENCES [dbo].[GUnit] ([UnitUID]) ON DELETE CASCADE ON UPDATE CASCADE


