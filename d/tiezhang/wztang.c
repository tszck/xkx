// Room: /d/tiezhang/wztang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
string look_bian();

void create()
{
	set("short", HIY"五指堂"NOR);
	set("long", @LONG
這是一間完全用花崗巖砌成的大廳，透出陣陣逼人的寒氣。整座房
屋沒有窗戶，顯得陰森黑暗。兩旁的牆壁上插着松油火把，散發出昏黃
的光亮，寂靜的大廳中不時響起火把噼啪的燃燒聲。大廳的正中擺放着
幫主的寶座，兩旁分列着十幾把椅子，只有遇到幫中大事時，幫主才會
在這裏與部下商議。在正面的牆上掛着一面縷金的橫匾(bian)。北面有
一扇小門通向後面。
LONG	);
	set("item_desc", ([ 
		"bian" : (: look_bian :),
	]));
	set("exits", ([ 
		"east"      : __DIR__"zoulang1",
		"west"      : __DIR__"zoulang2",
		"north"     : __DIR__"hxfang",
		"southdown" : __DIR__"guangchang",
	]));
	set("objects", ([ 
		CLASS_D("tiezhang")+"/qqren" : 1,
		__DIR__"npc/xiaotong" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	
}
string look_bian()
{
	return
	"\n"HIY
	"          ####################################\n"
	"          ####                            ####\n"
	"          ####    五    指    擎    天    ####\n"  
	"          ####                            ####\n"
	"          ####################################\n"NOR;
	"\n";
}