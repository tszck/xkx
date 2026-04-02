// Room: /d/heimuya/didao2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","祕道");
	set("long", @LONG
你來到了一條祕道，看樣子它不太平常，若隱若顯的幾盞油燈，昏
暗如豆但是看上去前方似有光亮，你要是覺得害怕，現在回頭還是可以
的，不過這異常的幽靜卻也極大激發了你的好奇心，大丈夫死又何足道
哉，真是勇氣可佳。
LONG );

	set("exits",([
		"down"  : "/d/city/shilijie4",
		"west"  : __DIR__"didao1", 
		"south" : __DIR__"didao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
