// /guanwai/xiaotianchi.c

inherit ROOM;

void create()
{
	set("short", "小天池");
	set("long", @LONG
小天池又稱長白鏡湖，圓圓如鏡。湖水碧藍，林海峭壁倒映其間，
風光幽麗，一層綠裏透紅的細沙，均勻地鋪在湖底，恰似展開着的一幅
金絲絨毯。相傳天上仙女每日天池中沐浴，洗畢就到天豁峯的峯顛，坐
在兩個峯尖中間的開闊岩石上，對着小天池打扮梳妝，故名鏡湖。
LONG );
	set("exits", ([
		"eastup"  : __DIR__"pubu",
		"west"    : __DIR__"heifengkou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6180);
	set("coor/y", 5200);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}