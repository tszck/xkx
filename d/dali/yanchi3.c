//Room: /d/dali/yanchi1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","沿池堤岸");
	set("long",@LONG
這裏是滇池遊客聚集之處，演鄯候高生世就時時承舟優勝於煙水
緲藹的滇池，欣賞“梵剎於滇波向仰抑”的美景，並常停舟官渡，飲
酒賦詩，被稱之為“停舟煙會”。這裏的東浦彩虹、西山白雨、空中
鷺鷥、晚霞潮紅、歸帆遠影、無不給人以美的享受。
LONG);
	set("objects", ([
	   __DIR__"npc/guigongzi": 1,
	   __DIR__"npc/enu": 2,
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"yanchi2",
	    "southeast" : __DIR__"luojiadian",
	]));
	set("coor/x", -33000);
	set("coor/y", -70500);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}