<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    $uploadsDir = __DIR__ . DIRECTORY_SEPARATOR . 'uploads';
    //echo "<p>$uploadsDir</p>";
    $targetFilename = $uploadsDir . DIRECTORY_SEPARATOR . 'my-image.jpeg';
    /* Here minus 5 is done becoz I will start server from localhost directory
        This just done for getting the path relative to the root directory
    */
    $relativeFilename = substr($targetFilename, strlen(__DIR__) - 5);
    //echo "<p>$relativeFilename</p>"; // Outputs -> /mod2/uploads/my-image.jpeg

    /* $_FILES is an associative array with the form of an input name as an entry key and the
        upload information as an entry value. The upload information is another associative
        array with the following fields: name, tmp_name, type, size, and error 
    */
    if (array_key_exists('uploadFile', $_FILES)) {
        $uploadInfo = $_FILES['uploadFile'];
        switch ($uploadInfo['error']) {
            case UPLOAD_ERR_OK:
                if (mime_content_type($uploadInfo['tmp_name']) !== 'image/jpeg') {
                    echo sprintf('The uploaded file [%s] is not JPEG image format.', $uploadInfo['name']);
                } else {
                    /* Moves the uploaded file to a new location [which is the uploads/my-image.jpeg] */
                    if (!move_uploaded_file($uploadInfo['tmp_name'], $targetFilename)) {
                        echo 'Cannot save the uploaded image.';
                    } else {
                        echo 'The file was uploaded successfully.';
                    }
                }
                break;
            case UPLOAD_ERR_INI_SIZE:
                /* the uploaded file size limit is 2 MB, and the POST payload limit is 8 MB (for the whole request) */
                echo sprintf('Failed to upload [%s]: the file is too big.', $uploadInfo['name']);
                break;
            case UPLOAD_ERR_NO_FILE:
                echo 'No file was uploaded.';
                break;
            default:
                echo sprintf('Failed to upload [%s]: error code [%d].', $uploadInfo['name'], $uploadInfo['error']);
                break;
        }
    }

    /* Show the uploaded file if it is uploaded [It will appear in the uploads directory with the name my-image.jpeg] */
    if (file_exists($targetFilename)) {
        /* It will go to  http://localhost:8080/mod2/uploads/my-image.jpeg */
        echo sprintf('<br><img src="%s" style="max-width: 500px; height: auto;" alt="my uploaded image">', $relativeFilename);
    }

    ?>

    <form action="./super-post-upload.php" method="post" enctype="multipart/form-data">
        <!-- This attribute name="uploadFile" is used as a key in $_FILES  -->
        <input type="file" name="uploadFile">
        <input type="submit" value="Upload">
    </form>


</body>

</html>