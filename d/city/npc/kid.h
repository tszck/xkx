string *food_name = ({
"翡翠燒賣", "鴨菜包子", "千層油糕", "芝麻包子", 
});

string ask_secret()
{
    string food =  food_name[ random( sizeof( food_name ) ) ];
    command( "en" );
    command( "think" );
    command( "tell " + (string)this_player()->query( "id" ) + 
        " 你幫我買個" + food );
    this_player()->set_temp( "kid_ask/" + query( "id" ), food );
    return "怎麼樣？幫我買了，我就告訴你！\n";
}

int accept_object( object me, object ob)
{
    string food, id = me->query( "id" );
    food = (string)me->query_temp( "kid_ask/" + query( "id" ) ) ;
    if ( food && food == ob->name() )
    {
        command( "grin " + id );
        command( "tell " + id + " 我的祕密是：我老爸叫" 
        + query( "papa_name" ) + "。" );
        command( "laugh1 " + id );
        me->delete_temp( "kid_ask/" + query( "id" ) );
        return 1;
    }
    command( "look " + id );
    command( "sigh " + id );
    return 0;
}

