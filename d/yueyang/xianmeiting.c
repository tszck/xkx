// Room: /d/yueyang/xianmeiting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "仙梅亭");
	set("long", @LONG
仙梅亭位於嶽陽樓的南面，相傳明朝崇禎年間重修嶽陽樓挖掘地基
時，掘出一塊石板，石板潔白如玉，一面有一枝枯梅，若隱若現二十四
萼，紋理蒼勁、如仙家所畫，人們以爲是仙蹟，便修一小亭，立石其中
，以爲紀念。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"yueyanglou1",
	]));
	set("coor/x", -1450);
	set("coor/y", -2270);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
