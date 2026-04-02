// /guanwai/pubu.c

inherit ROOM;

void create()
{
	set("short", "長白瀑布");
	set("long", @LONG
天池水從兩百餘尺高飛流跌落，轟鳴之聲遠傳數裏，水花直落大嶂
谷，與天然屏障玉壁、金壁相映，恰似白練當空，水柱撲向深深的谷底，
濺起幾丈高的飛浪，猶如仙女散花，陽光照射下，虹飛氤躍，璀燦壯觀
之極。古人詩云：“白河兩岸景清幽，碧水懸崖萬古留；疑似龍池噴瑞
雪，如同天際掛飛流。不須鞭石渡滄海，直可乘槎問鬥牛？欲識林泉真
樂趣，明朝結伴再來遊。”
LONG );
	set("exits", ([
		"southeast"  : __DIR__"damen",
		"westdown"   : __DIR__"xiaotianchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5200);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}