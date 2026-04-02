// Room: /yangzhou/shiliji5.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里長街");
	set("long",@LONG
十里長街原本是揚州的中心，繁華之至。街邊茶肆酒樓林立，店鋪
面街開店，熱鬧非凡，每當夜市來臨時，店家高掛燈籠，盡夜喧譁，燈
火不絕。杜牧曾描繪到：“每重城向夕，常有絳紗燈萬數，輝煌羅列空
中。”現在街邊的店鋪多搬至新城，十里長街的繁榮教往昔已遜色許多，
但做為進出揚州的要道，依舊行人擁擠，車馬如流。街西是一家錢莊，
可以聽到叮叮噹噹的金銀聲音。東邊連着秦淮客寓。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"qianzhuang",
		"east"  : __DIR__"kedian",
		"south" : __DIR__"shilijie6",
		"north" : __DIR__"shilijie4",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}