// Room: /yangzhou/waifang.c
// Last Modified by Winder on Jul. 20 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","媚香樓");
	set("long",@LONG
外房陳設幽雅，雕樑畫棟，繡幕羅幃，地鋪五彩絨氈，壁懸八愛名
畫，中掛湘竹燈四，系繪《六才》全本。中設楠木天然幾，大理石四仙
木桌，古銅瓶中養碧桃一枝。壁廂位置竹葉瑪瑙榻牀，紅木圓臺，甚是
精巧。旁有一紗櫥，櫥門啓處，別有洞天。
LONG );
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"woshi",
		"south" : __DIR__"meixiangyuan",
	]));
	set("objects", ([
		__DIR__"npc/lulixian" : 1,
	]));
	create_door("east", "紗櫥門", "west" , DOOR_CLOSED); 
	set("coor/x", 41);
	set("coor/y", 21);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}