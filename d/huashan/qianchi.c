// qianchi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "千尺幢");
	set("long", @LONG
前面有一斜如天垂石梯的山階，這就是赫赫有名的千尺幢，千尺幢
是依一陡峭巖脊的裂縫開鑿而成，斜度約七十度，高約二十米，僅容一
人上落。抬頭僅見一線天光，兩旁巖壁陡峭，盡頭是個僅能容身的方形
石洞，俗稱“天井”，天井旁的危崖上刻有“太華咽喉”的題刻。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"huixinshi",
		"southup" : __DIR__"baichi",
	]));
	set("objects", ([
		__DIR__"npc/youke": 2,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 240);
	set("coor/z", 40);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if (dir == "southup" && userp(me))
	{
		me->receive_damage("jing", 30);
		me->receive_damage("qi", 30);
	}
	return 1;
}
