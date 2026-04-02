//Room: /d/dali/jingzhuang6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","第六層");
	set("long",@LONG
有神龕五座，內中雕有佛像浮雕二百餘座。佈局嚴密，層次分明；
表情各異，比例協調；刀痕尤勁，備極精巧；線條流暢，栩栩如生；
不愧是滇南石雕藝術的珍品。世代金文家皆贊“滇中藝術，此極品也
”。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang7",
	    "down"  : __DIR__"jingzhuang5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36000);
	set("coor/y", -70400);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}