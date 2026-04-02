// Room: workroom.c


inherit ROOM;
int do_drop(object me, object obj);
int all;
void create()
{
	set("short", "垃圾處理場");
	set("long", @LONG
這裏是揚州的地下垃圾處理場。有公德心的玩家總是
會把垃圾扔到這個地方來。旁邊就是一個垃圾堆，有什麼
不需要的東西，就扔(drop)吧。
LONG );
	set("exits", ([
		"up" : __DIR__"shilijie4",

	]));
	setup();
	seteuid(getuid());
}
void init()
{
	add_action("drop","drop");
}
int drop(string arg)
{
	object me=this_player();
	object obj, *inv, obj2;
	int i, amount;
	string item;
 	all=0;
 	if(!arg) return notify_fail("你要丟下什麼東西？\n");

	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");

	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上沒有這樣東西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分開丟棄。\n");
		if( amount < 1 )
			return notify_fail("東西的數量至少是一個。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		if (sizeof(inv)>=20) all=1;
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		if (all!=1)
		  write("Ok.\n");
    else
      message_vision("$N把身上的東西都扔進垃圾堆。\n",me); 
	return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上沒有這樣東西。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;

	if( obj->query_temp("is_rided_by") == me)
		return notify_fail( obj->name() + "不是正被你騎着。\n");
	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "這樣東西不能隨意丟棄。\n");
	if (obj->move(environment(me))) {
		if (all!=1)
		{
			if( obj->is_character() )
				message_vision("$N將$n從背上放了下來，躺在地上。\n", me, obj);
     	else if(obj->value())
				message_vision( sprintf("$N丟下一%s$n。\n",	obj->query("unit")), me, obj );
   	 	else
   	 	{
   	 		message_vision(sprintf("$N把一%s$n扔進垃圾堆。\n",	obj->query("unit")), me, obj );
   	 	}
    }
  }
	if( !obj->value() && !obj->is_character())
	{
  	if (obj->query("value")) me->add("balance",1);
   	destruct(obj);    
  }
		return 1;
}
