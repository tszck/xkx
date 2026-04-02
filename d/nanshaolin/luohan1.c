// Room: /d/nanshaolin/luohan1
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "羅漢堂一部");
	set("long", @LONG
這是一間極為簡陋的禪房。環視四周，除了幾幅佛竭外，室內空蕩
蕩地別無他物。地上整齊的擺放着幾個破爛且發黑的黃布蒲團，幾位須
發花白的老僧正在坐在上面閉目入定。這裏是本寺十八羅漢參禪修行的
地方，不少絕世武功便是在此悟出。
LONG );
	set("exits", ([
		"north" : __DIR__"luohan2",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanfen" : 1,
	]));
	set("coor/x", 1760);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

