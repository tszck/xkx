// /kaifeng/yuwang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "禹王臺");
	set("long", @LONG
禹王臺建造於小山丘之上，這裏風景優美，環境幽雅，自古以來就
是人們遊春登高的勝地。相傳春秋時期，晉國盲人樂師曠常在此吹奏古
樂，故名『吹臺』。
LONG);
	set("objects", ([
		__DIR__"npc/woman" : 1,
	]));
	set("exits", ([
		"west"   : __DIR__"shulin",
		"eastup" : __DIR__"yuwangmiao",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
