﻿CREATE PROCEDURE [dbo].[test_item_list]
	@iUnitUID_ [bigint]
AS
SET NOCOUNT ON;

DECLARE @ItemList TABLE
(
    ItemUID int not null primary key,
    ItemID int not null,
    UsageType tinyint not null default(0),
    Quantity int not null default(0),
	Endurance int not null default(-1),
    InventoryCategory tinyint not null,
    SlotID tinyint not null,
	ELevel	smallint not null default (0),
	Socket1	smallint not null default (0),
	Socket2	smallint not null default (0),
	Socket3	smallint not null default (0),
	Socket4	smallint not null default (0),
	Socket5	smallint not null default (0)
)

INSERT INTO @ItemList(ItemUID, ItemID, InventoryCategory, SlotID)
    SELECT ItemUID, ItemID, InventoryCategory, SlotID
        FROM dbo.GItem WITH(NOLOCK)
            WHERE UnitUID = @iUnitUID_ AND Deleted = 0

UPDATE a
    SET a.UsageType = 2, a.Quantity = b.Quantity
        FROM @ItemList as a
            JOIN dbo.GItemQuantity as b WITH(NOLOCK) ON a.ItemUID = b.ItemUID

UPDATE a
    SET a.UsageType = 1, a.Endurance = b.Endurance
        FROM @ItemList as a
            JOIN dbo.GItemEndurance as b WITH(NOLOCK) ON a.ItemUID = b.ItemUID

UPDATE a
	SET a.ELevel = b.Elevel
		FROM @ItemList as a
			JOIN dbo.GItemEnchant as b WITH (NOLOCK)
				ON a.ItemUID = b.ItemUID

UPDATE a
	SET a.Socket1 = b.Socket1
,		a.Socket2 = b.Socket2
,		a.Socket3 = b.Socket3
,		a.Socket4 = b.Socket4
,		a.Socket5 = b.Socket5
		FROM @ItemList as a
			JOIN dbo.GItemSocket as b WITH (NOLOCK)
				ON a.ItemUID = b.ItemUID

SELECT  ItemUID
,       ItemID
,       UsageType
,       Quantity
,		Endurance
,       InventoryCategory
,       SlotID
,		ELevel
,		Socket1
,		Socket2
,		Socket3
,		Socket4
,		Socket5
    FROM @ItemList order by inventorycategory


