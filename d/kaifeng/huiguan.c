// /kaifeng/huiguan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "山陝甘會館");
	set("long", @LONG
山陝甘會館是山西，陝西，甘肅的富商巨賈建造的，是旅汴同鄉聚
會的場所，就是給這三地的人聚會的。當然也有在此來商談生意的。裏
面就是關帝廟。
LONG);
	set("exits", ([
		"west" : __DIR__"eroad2",
		"east" : __DIR__"paifang",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
