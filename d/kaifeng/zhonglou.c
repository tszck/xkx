// /kaifeng/zhonglou.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "鐘樓");
	set("long", @LONG
一座小巧而高聳的閣樓，用上好的檜木所建，有一股淡淡的清香。
樓上的鐵鐘淨重一萬八千斤，是當年相國寺高僧雲遊天下，佈施而成的。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"qianyuan",
	]));

	setup();
	replace_program(ROOM);
}
