// Room: /yanziwu/ganquanjie.c
// Date: Jan.28 2000 by Winder

inherit ROOM;
void create()
{
	set("short","甘泉街");
	set("long",@LONG
甘泉街原本是揚州最繁華的街道之一，由於小秦淮河東岸的揚州新
城的擴建，商家多搬去新城了，甘泉街才冷清許多，也乾淨許多。在新
城未建之前，甘泉街南北兩面盡是茶肆酒樓，各色店鋪。店家紛紛侵街
搭設涼棚，擺設花木，裝飾店面，造成街道擁擠不堪，河對面的漕運署
官員的車馬無法通行，所以特建新城，把店鋪挪至對岸。北面是揚州最
著名的酒樓，陣陣肉香酒香讓你垂涎欲滴。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"kedian",
		"north" : __DIR__"zuixianlou",
		"east"  : __DIR__"ninghaiqiao",
		"west"  : __DIR__"shilijie4",
	]));
	set("objects", ([
		CLASS_D("baituo")+"/ouyangke" :1,
	]));
	set("coor/x", 20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}