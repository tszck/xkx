// /kaifeng/kaifeng.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "開封府大堂");
	set("long", @LONG
兩排的衙役站立兩邊，再旁邊是龍頭，虎頭，狗頭三把鍘刀，白亮
的鋒刃令人寒毛直豎。臺桌後高掛『明鏡高懸』的匾額。上了大堂，無
事也膽寒，東面出去就是街道。
LONG
	);
	set("objects", ([
		__DIR__"npc/baozheng" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"kaifeng",
	]));

	setup();
	replace_program(ROOM);
}
