<?php 

/**
 * 
 */
class Database
{

	public $host = DB_HOST;
	public $user = DB_USER;
	public $pass = DB_PASS;
	public $dbname = DB_NAME;

	public $link;
	public $error;
	
	function __construct()
	{
		$this->getConnection();
	}

	private function getConnection(){
		$this->link=new mysqli($this->host,$this->user,$this->pass,$this->dbname);

		if(!$this->link){
			$this->error="Connection fail....!".$this->link->connect_error;
			return false;
		}
	}

	public function getLocation($query){
	    $result=mysqli_query($this->link,$query);
        return $result;
    }

}

 ?>