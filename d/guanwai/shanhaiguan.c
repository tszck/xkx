// /guanwai/shanhaiguan.c
inherit ROOM;

void create()
{
	set("short", "山海關");
	set("long", @LONG
這裏就是萬裏長城最東面的重要關口----山海關。這裏地勢險要，
自古就是關外通往中原的必經之地。站在關樓上北望，角山，古堡，烽
火臺歷歷在目，南沿長城遠眺，直深入海的老龍頭依稀可見。城樓二樓
上懸掛着一塊巨幅橫匾(bian)。
LONG );
	set("exits", ([
		"northeast" : __DIR__"road1",
		"southeast" : __DIR__"laolongtou",
		"up"        : "/d/changcheng/shanhaiguan",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	set("item_desc",([
		"bian" :
"
    **************************************
    ********　　　　　　　　　　　********
    ********　天  下  第  一  關  ********
    ********　　　　　　　　　　　********
    **************************************\n",
	]));
 	set("outdoors", "guanwai");
	set("coor/x", 5000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
