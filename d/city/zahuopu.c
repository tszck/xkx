// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "雜貨鋪");
	set("long", @LONG
這是一家小小的雜貨鋪，大箱小箱堆滿了一地，都是一些日常用品。
楊掌櫃懶洋洋地躺在一隻躺椅上，招呼着過往行人。據説私底下他也賣
一些貴重的東西。攤上立着一塊招牌(zhaopai)。
LONG );
	set("item_desc", ([
		"zhaopai": "請用 \"list\" 列出貨物表，\"buy\" 向老闆購物。\n",
	]));
	set("exits", ([
		"east" : __DIR__"shilijie6",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 5);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}