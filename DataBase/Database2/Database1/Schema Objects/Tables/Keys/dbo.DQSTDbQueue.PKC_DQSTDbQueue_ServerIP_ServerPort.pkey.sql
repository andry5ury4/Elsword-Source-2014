﻿ALTER TABLE [dbo].[DQSTDbQueue] ADD CONSTRAINT [PKC_DQSTDbQueue_ServerIP_ServerPort] PRIMARY KEY CLUSTERED  ([ServerIP], [ServerPort]) WITH FILLFACTOR=80 ON [PRIMARY]

