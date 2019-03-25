<?php
/**
 * Created by PhpStorm.
 * User: SUJAN HASAN
 * Date: 3/25/2019
 * Time: 12:48 AM
 */
?>
<?php
include 'lib/config.php';
include 'lib/mydatabase.php';

$db=new Database();
$output="";

$query="select * from tracking_info order by id desc limit 1";
$result=$db->getLocation($query);
if(mysqli_num_rows($result)>0){
    while ($row=mysqli_fetch_assoc($result)){
        $output.="<input type='text' id='lat_loc' value='".$row['lat']."'>";
        $output.="<input type='text' id='lan_loc' value='".$row['lng']."'>";
    }
    echo $output;
}

?>
