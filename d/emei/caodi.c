// Room: /d/emei/caodi.c
inherit ROOM;
int do_search();
void end(object);
void create()
{
	set("short", "草地");
	set("long", @LONG
這裏就是古德林中的一片草地了。這裏野草從生，高過人頭，偶爾有小獸
從草中穿過，整個地方陰森恐怖，周圍是一整片黑森森的樹林。
LONG
	);
	set("objects", ([
		CLASS_D("emei")+"/fengling" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
	    "south" : __DIR__"gudelin3",
	]));
	set("coor/x", -6130);
	set("coor/y", -1070);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search()
{
	object me = this_player();
 
	int jing;
	if( me->is_busy() ) return notify_fail("你上一個動作還沒有完成呢。\n");
	if(jing<30) return notify_fail("你無法集中精力查看！\n");
	message_vision("$N開始查看這裏的一草一木，希望能找到一棵草藥什麼的。\n",me);
	me->start_busy(2);
	me->receive_damage("jing", 10);
	call_out("end",3,me);
	return 1;
}
void end(object me)
{
	object ob;
	switch(random(10))
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			message_vision("$N累了個半死，結果什麼都沒有找到。\n",me);
			break;
		default: ob=new(__DIR__"obj/caoyao");
			ob->move(me);
			message_vision("$N找到了一片草藥，放在$N的身上。\n",me);
			break;
	}
}