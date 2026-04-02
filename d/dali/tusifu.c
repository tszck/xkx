//Room: /d/dali/tusifu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","土司府");
	set("long",@LONG
土司府是當地傣族世襲土司刀氏的衙門，一座古老的磚木建築物，
門庭居高臨下，莊嚴堅實，門前是寬廣的石階，有點象衙門氣勢，房
屋共三臺，佔地約八百畝，分作正廳，議事廳，後廳，廂房。
LONG);
	set("objects", ([
	   __DIR__"npc/datusi": 1,
	   __DIR__"npc/shicong": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : __DIR__"tusimentang",
	    "south"  : __DIR__"dahejiewest",
	]));
	set("coor/x", -41000);
	set("coor/y", -71020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}