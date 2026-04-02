
inherit NPC;

void  create()
{
	set_name("小販",({"changer"}));
	setup();
}	

int  do_list()
{
	string *goods;
	int i;
	
	if ( !arrayp(goods=this_object()->query("exchangeable_goods")) || !sizeof(goods) )
		return notify_fail( "目前沒有可交換的東西。\n" );
			
	printf( "你可以向%s交換下列物品：\n", query("name") );
	for ( i = 0; i < sizeof(goods); i++ )
	  printf( "%s\n", goods[i]->short() );
	return 1;
}	

int do_change( string arg )
{
	object me=this_player();
	object ob1,ob2;
	string *str, *wgoods, *egoods;
	int i;
	
	if (!stringp(arg))
		return notify_fail( "你要拿什麼換？\n" );
	str = explode( arg, " " );
	if ( sizeof( str ) != 3  || str[1] != "to" )
		return notify_fail( "命令格式是：change sth. to sth.\n" );
	if ( !objectp( ob1 = present(str[0],me) ) )
		return notify_fail( "你身上沒有這樣東西。\n" );					
	egoods = query( "exchangeable_goods" );		
	if ( !arrayp(egoods) )
		return notify_fail( "目前還沒有物品可供交換。\n" );
	wgoods = query( "want_goods" );
	if ( !arrayp(wgoods) )
		return notify_fail( "他並不需要什麼東西。\n" );		
	for ( i = 0; i < sizeof(wgoods); i++ )
	  if ( wgoods[i]->query("id") == str[0] )  break;
	if ( i >= sizeof(wgoods) )
		return notify_fail( "他並不需要這樣東西。\n" );
	for ( i = 0; i < sizeof(egoods); i++ )
	  if ( egoods[i]->query("id") == str[2] )  break;
	if ( i >= sizeof(egoods) )
		return notify_fail( "他沒有這樣東西和你交換。\n" );
	ob2 = new( egoods[i] );
	message_vision( "$N拿出一" + ob1->query("unit") + ob1->query("name") + 
			"和" + query("name") + "換了一" + ob2->query("unit") + ob2->query("name") + "。\n", me );
	destruct( ob1 );
	ob2->move( me );
	return 1;
	
}