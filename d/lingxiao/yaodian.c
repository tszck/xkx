// Room: /d/lingxiao/yaodian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "回春居");
	set("long", @LONG 
這就是凌霄城中醫術最高明的戴大夫所開的回春居，一進這裏，就
聞到一股刺鼻的藥味，只見房中擺滿了大大小小的箱籠、藥櫃。一名須
發皆白的老人坐在桌旁，正在替一人把脈。旁邊的牆上貼着一張張條幅
(tiaofu)，都是被戴大夫治好了的病人送的。
LONG );
	set("no_fight",1);
	set("item_desc", ([
		"tiaofu" : "華佗再世，扁鵲重生。\n",
	]));
	set("objects", ([
		__DIR__"npc/daifu" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"iceroad2",
	]));
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

