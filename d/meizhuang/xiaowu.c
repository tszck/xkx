// /d/meizhuang/xiaowu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "琴堂");
	set("long", @LONG
你進了這間琴堂以後，發現這裏竟然和你想象的差別很大，這裏雖
然不能説是金碧輝煌，但到處都是玉製的物器，玉桌，玉椅，玉屏風，
玉茶壺，玉杯......數不勝數。牆上掛着一根綠玉蕭和一具白玉瑤琴。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out"   : __DIR__"xiaoyuan",
		"north" : __DIR__"neishi",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("heimuya")+"/gong" : 1,
	]));

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", 20);
	setup();
}
