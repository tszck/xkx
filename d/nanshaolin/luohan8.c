// Room: /d/nanshaolin/luohan8.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "羅漢堂八部");
	set("long", @LONG
這是一間極爲簡陋的禪房。環視四周，除了幾幅佛竭外，室內空蕩
蕩地別無他物。地上整齊的擺放着幾個破爛且發黑的黃布蒲團，幾位須
發花白的老僧正在坐在上面閉目入定。這裏是本寺十八羅漢參禪修行的
地方，不少絕世武功便是在此悟出。
LONG );
	set("exits", ([
		"south" : __DIR__"luohan7",
		"north" : __DIR__"luohan9",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanxi" : 1,
	]));
	set("coor/x", 1760);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

