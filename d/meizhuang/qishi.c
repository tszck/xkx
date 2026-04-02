// /d/meizhuang/qishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "棋室");
	set("long", @LONG
這裏便是二莊主黑白子的棋室了，棋室裏兩張石凳，一張石几，石
几上用黑白子的指力刻着縱橫九九八十一道，這裏除了簡單的放着兩盒
用玉做成的棋子外，什麼都沒有，顯是怕雙方對弈時分心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zoulang2",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/zi" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
