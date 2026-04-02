// Room: /d/shaolin/banruo5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "般若堂五部");
	set("long", @LONG
這是一間極爲簡陋的禪房。環視四周，除了幾幅佛竭外，室
內空蕩蕩地別無他物。地上整齊的擺放着幾個破爛且發黑的黃布
蒲團，幾位鬚髮花白的老僧正在坐在上面閉目入定。這裏是本寺
十八羅漢參禪修行的地方，不少絕世武功便是在此悟出。一位小
沙彌在一邊垂手站立。
LONG );
	set("exits", ([
		"east" : __DIR__"wuchang1",
		"south" : __DIR__"banruo4",
		"north" : __DIR__"banruo6",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-nan" : 1,
		CLASS_D("shaolin") + "/cheng-zhi2" : 1,
		__DIR__"npc/xiao-nan" : 1
	]));
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 830);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}