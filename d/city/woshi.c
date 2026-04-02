// Room: /yangzhou/woshi.c
// Last Modified by Winder on Jul. 20 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","臥室");
	set("long",@LONG
沿窗列一紫檀妝臺，上用繡花紅呢罩。一榻牀，榻前懸一立軸，系
繪《文君私奔圖》。左右楹聯(lian)筆法甚秀。珠簾隱隱，香霧沉沉，
其最雅者朝外排一牀，周圍皆書畫，紗窗內懸異式珠燈，外懸湖色牀幔，
左右垂銀絲鉤。幔之內懸一小額曰“溫柔鄉”，流蘇帳，鴛鴦被，合歡
枕，俱異香可愛。
LONG    
	);
	set("exits",([ /* sizeof() == 3 */
		"west" : __DIR__"waifang",
	]));
	set("item_desc" , ([
		"lian" :"	仙       麗\n"
			"	才       句\n" 
			"	俊       妙\n" 
			"	似       於\n" 
			"	東       天\n" 
			"	海       下\n"
			"	青       白\n",
	]));
	create_door("west", "紗櫥門", "east" , DOOR_CLOSED); 
	set("coor/x", 60);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}