﻿ALTER TABLE [dbo].[GItemQuantity] ADD
CONSTRAINT [FK_GItemQuantity_GItem] FOREIGN KEY ([ItemUID]) REFERENCES [dbo].[GItem] ([ItemUID]) ON DELETE CASCADE ON UPDATE CASCADE


