inherit ROOM;

void create()
{
	set("short", "雜貨鋪");
	set("long", @LONG
這是一家雜貨鋪，大箱小箱堆滿了一地，都是一些日常用品。胡掌
櫃懶洋洋地躺在一隻躺椅上，招呼着過往行人。據說私底下他也賣一些
貴重的東西。攤上立着一塊招牌(zhaopai)。
LONG );
	set("item_desc", ([
		"zhaopai": "請用 \"list\" 列出貨物表，\"buy\" 向老闆購物。\n",
	]));
	set("exits", ([
		"east" : __DIR__"xidan",
	]));
	set("objects", ([
		__DIR__"npc/hu": 1,
	]));
	set("coor/x", -230);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
