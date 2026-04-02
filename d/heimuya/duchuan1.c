// Room: /d/heimuya/duchuang1.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;
int arrive(object me,int i);

void create()
{
	set("short", "渡船");
	set("long", @LONG
一葉小舟，一次就能載七、八個人。一名三十多歲日月教徒裝扮的
艄公手持長竹篙，正在船尾撐着船，這艄公臂力驚人，小舟在他的操控
之下，一支箭般飛快地射向對岸。
LONG );
	set("no_clean_up", 0);
	set("outdoors", "heimuya");
	set("coor/x", -3100);
	set("coor/y", 4040);
	set("coor/z", -10);
	setup();
}
void init()
{
	object me = this_player();
	if (me->query("family/master_id")=="dongfang bubai")
	{
		message_vision("幫衆見是$N教主座下弟子，絲毫不敢怠慢，立即起航。\n",me);
		arrive(me,1);
	}
	else
	call_out("arrive", 5, this_player(),0);
}

int arrive(object me,int i)
{
	message_vision("幫衆奮力划船，船行如飛，片刻就把$N送到了彼岸。\n", me);
	if (intp(i) && i==1)
	{
		if(me->query_temp("hmy_ship/ct")) me->move(__DIR__"xingxingtan",1);
		else me->move(__DIR__"changtan",1);
	}
	else
	{
		if(me->query_temp("hmy_ship/ct")) me->move(__DIR__"xingxingtan");
		else me->move(__DIR__"changtan");
	}
	me->delete_temp("hmy_ship");
}
