// /d/changan/dangpu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "南北行");
	set  ("long",  @LONG
這是一家氣派不小的雜貨鋪，門樓高掛一個牌匾，上書紅底金色三
個大字----“南北行”。掌櫃懶洋洋地坐櫃枱後，幾個夥計忙裏忙外。
櫃枱上立着一塊招牌(zhaopai)。
LONG);
	set("item_desc", ([
		"zhaopai": "請用 \"list\" 列出貨物表，\"buy\" 向老闆購物。\n",
	]));
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"southroad1",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/zhanggui" : 1,
	]));
	set("coor/x", -5030);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
