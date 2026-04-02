// Room: /d/taohua/hill.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "小山");
	set("long", @LONG
一翻上山頭，你就發現眼前豁然開朗，北面山腳下是一大片的桃花
叢，而在花叢中隱約露出了幾座庭院的飛檐，似乎有着一片典雅的建築
在那邊。向靠海的一邊望去，用來爬山時墊腳的岩石已經被蹬掉了，你
再也回不到海邊了。而東北邊更有一座小山峯，十分險峻。
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"taohua1",
		"eastup" : __DIR__"hill1",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8500);
	set("coor/y", -4690);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
