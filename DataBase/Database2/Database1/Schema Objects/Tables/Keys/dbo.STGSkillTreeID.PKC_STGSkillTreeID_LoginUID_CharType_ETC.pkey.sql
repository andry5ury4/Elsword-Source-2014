﻿ALTER TABLE [dbo].[STGSkillTreeID] ADD CONSTRAINT [PKC_STGSkillTreeID_LoginUID_CharType_ETC] PRIMARY KEY CLUSTERED  ([LoginUID], [CharType], [Promotion], [SkillID]) WITH FILLFACTOR=80 ON [PRIMARY]


