// Room: /d/henshan/chaguan.c
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "衡陽茶館");
	set("long", @LONG
你一走進來，就聞到一股茶香沁入心脾，精神爲之一爽。幾張八仙桌一字
排開，坐滿了客人，或高聲談笑，或交頭接耳。你要想打聽江湖掌故和謠言，
這裏是個好所在。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"hengyang",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));
//        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
