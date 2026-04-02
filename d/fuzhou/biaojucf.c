// Room: /city/biaojucf.c

inherit ROOM;

void create()
{
	set("short", "鏢局廚房");
	set("long", @LONG
福威鏢局對夥計們十分款待，不但每月有薪金，而且還包喫住。這
裏就是夥計們一日三餐的地方。廚房的牆上掛滿了鍋碗瓢盆，還有一些
風乾的滷味兒。房中放着一張長臺，長臺的周圍擺着幾條長凳。
LONG
        );
	set("exits", ([
		"south" : __DIR__"biaojuhy",
	]));
	set("objects", ([
		__DIR__"npc/hua" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6295);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
