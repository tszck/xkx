inherit RESTROOM_OUT;

void create()
{
	set("short", "思過室");
	set("long", @LONG
這是桃花島上供本門弟子閉門思過的地方。屋裏僅僅放着一張牀，
顯得空蕩蕩的。四面則是光禿禿的牆壁，看上去黑黝黝的，原來卻是鐵
築的。靠門的地方有一小洞，洞邊放着一隻碗。往西是一間不起眼的小
屋，門上掛了個牌子「桃花軒」。
LONG );
	set("exits", ([
		"south"  : __DIR__"liangongfang",
	]));
	set("objects", ([
		__DIR__"npc/mei" : 1,
	]) );	
//	set("no_clean_up", 0);
	set("coor/x", 8980);
	set("coor/y", -2990);
	set("coor/z", 0);
	set("door_name","門");
	set("door_dir","west");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","門上掛了個牌子：桃花軒。\n");
	set("inside_msg",   "門上掛了個牌子：打擾一次、罰跪三天！\n");
	set("no_one_msg",   "門上掛了個牌子：桃花島弟子休息室。\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
