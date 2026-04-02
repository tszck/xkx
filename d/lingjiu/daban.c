//ROOM daban.c

inherit ROOM;

string look_jingzi();
void create()
{
	set("short","綴錦閣");
	set("long",@LONG
這是日常梳妝打扮的地方，放着一張紅木梳妝枱 ， 正對着你的是
一面光潤的銅鏡(jingzi)，梳妝枱上散落着一些胭脂花粉。臺旁擺着鬥
大的一個汝瓷花囊，插着滿滿的水晶球兒般的白菊。
LONG );
	set("exits", ([
		"west" : __DIR__"changl14",
	]));
	set("objects", ([
		__DIR__"npc/chengqs" : 1,
	]));
	set("item_desc", ([
		"jingzi" : (: look_jingzi :) ,
	]));
	set("coor/x", -50960);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
}

string look_jingzi()
{
	object me=this_player();

	message_vision("$N偷眼看着鏡中的自己。\n",me);	
	if ((string)me->query("gender")=="女性")
		return "你抬眼往鏡中瞧去，只見一個貌若春花的女子脈脈含情地凝望着你。\n你臉上一熱，羞澀地低下了頭，心想：那就是我嗎？\n";
	if ((string)me->query("gender")=="男性")
		return "你抬眼往鏡中瞧去，只見一個五大三粗的男子在鏡中直瞪着你。\n你不覺心想：唉，這麼雅緻之處我真不好意思待著了。\n";
	if ((string)me->query("gender")=="無性")
 		return "你抬眼往鏡中瞧去，只見一個不男不女的人影恍惚鏡中。\n你不覺心想：唉，為什麼爹媽沒給我一個女兒身呢？\n";
}