// /kaifeng/maofang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "小茅房");
	set("long", @LONG
在空地上搭起的一個小茅房。連遮擋的門都沒有。就在平地上挖了
個大坑，上面鋪上兩塊木板。嗡嗡的蒼蠅圍着你亂轉。一股臭味燻得人
直想逃出去，北面是片菜地，東面是個糞窖。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"caidi5",
		"east" : __DIR__"fenjiao",
	]));

	setup();
	replace_program(ROOM);
}
