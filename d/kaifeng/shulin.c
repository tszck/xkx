// /kaifeng/shulin.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
一片雜樹林，落葉掉了滿地，斑駁的枝葉顯露出天氣的無
情。綠色的小草就從樹之間的空隙長出來。林中點點的都是綠
色。小路穿過樹林不遠就是禹王臺。東南是中州方向。
LONG);
	set("no_clean_up", 0);

	set("exits", ([
		"southeast":__DIR__"guandao1",
		"northwest" : __DIR__"dadao1",
		"east" : __DIR__"yuwang",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
