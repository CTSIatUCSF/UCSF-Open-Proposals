<?php
/**
 * @file
 * op_user_fields.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function op_user_fields_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__departments';
  $strongarm->value = array();
  $export['field_bundle_settings_taxonomy_term__departments'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__schools';
  $strongarm->value = array();
  $export['field_bundle_settings_taxonomy_term__schools'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_user__user';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '30',
        ),
        'account' => array(
          'weight' => '-10',
        ),
        'timezone' => array(
          'weight' => '6',
        ),
        'picture' => array(
          'weight' => '5',
        ),
        'contact' => array(
          'weight' => '5',
        ),
        'wysiwyg' => array(
          'weight' => '5',
        ),
        'googleanalytics' => array(
          'weight' => '25',
        ),
      ),
      'display' => array(
        'summary' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_user__user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'op_deploy_op_terms_op_user_fields';
  $strongarm->value = array(
    'departments' => array(
      'terms' => array(
        0 => array(
          'name' => '',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        1 => array(
          'name' => 'Academic Affairs',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        2 => array(
          'name' => 'Anesthesia',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        3 => array(
          'name' => 'Anthropology, History, Soc Med',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        4 => array(
          'name' => 'AVC CLS FM Admin',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        5 => array(
          'name' => 'AVC Ethics & Compliance',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        6 => array(
          'name' => 'BioEngineering&Therapeutic Sci',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        7 => array(
          'name' => 'Campus Procurement&Contracting',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        8 => array(
          'name' => 'Cardiovascular Research Inst',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        9 => array(
          'name' => 'Cell & Tissue Biology',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        10 => array(
          'name' => 'Cell Culture Facility',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        11 => array(
          'name' => 'Center for Health & Community',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        12 => array(
          'name' => 'Clinical & Translational Sci',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        13 => array(
          'name' => 'Community Health Systems',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        14 => array(
          'name' => 'CTSI',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        15 => array(
          'name' => 'Dean\'s Office Sch of Pharmacy',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        16 => array(
          'name' => 'Dean\'s Office-Dentistry',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        17 => array(
          'name' => 'Dean\'s Office-Nursing',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        18 => array(
          'name' => 'Deans Office-Sch of Medicine',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        19 => array(
          'name' => 'Dept of Cell & Tissue Biology',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        20 => array(
          'name' => 'Dept Of Clinical Pharmacy',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        21 => array(
          'name' => 'Dept of Emergency Medicine',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        22 => array(
          'name' => 'Dept of Orofacial Sciences',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        23 => array(
          'name' => 'Development & Alumni Relations',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        24 => array(
          'name' => 'D_Cell and Tissue Biology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        25 => array(
          'name' => 'D_Ctr for the Hlth Professions',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        26 => array(
          'name' => 'D_OFS',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        27 => array(
          'name' => 'D_OMFS',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        28 => array(
          'name' => 'D_Preventive & Restor Dent Sci',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        29 => array(
          'name' => 'Emergency Medicine',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        30 => array(
          'name' => 'EVC Research',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        31 => array(
          'name' => 'EVC&P Business Services',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        32 => array(
          'name' => 'EVC&P Direct Office Activities',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        33 => array(
          'name' => 'E_AVC Ethics & Compliance',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        34 => array(
          'name' => 'E_Global Health Sciences',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        35 => array(
          'name' => 'E_Graduate Div',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        36 => array(
          'name' => 'E_Library',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        37 => array(
          'name' => 'E_Proctor Foundation',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        38 => array(
          'name' => 'E_Student Academic Affairs',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        39 => array(
          'name' => 'E_Vice Chanc Research',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        40 => array(
          'name' => 'F_Fin BRM and Risk',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        41 => array(
          'name' => 'F_FIN Procurement',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        42 => array(
          'name' => 'F_HR Human Resources',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        43 => array(
          'name' => 'F_IT Info Tech Svcs',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        44 => array(
          'name' => 'Gladstone Institutes',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        45 => array(
          'name' => 'HDF Comprehensive Cancer Ctr',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        46 => array(
          'name' => 'Inst For Health Policy Studies',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        47 => array(
          'name' => 'Inst For Neurodegen Diseases',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        48 => array(
          'name' => 'ITS-ITS Overall',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        49 => array(
          'name' => 'Langley Porter Hosp & Clinics',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        50 => array(
          'name' => 'MC UCOP Budget Reporting',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        51 => array(
          'name' => 'Mc2-moffit long consolidation',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        52 => array(
          'name' => 'MC3-CEO',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        53 => array(
          'name' => 'MC3-CIO',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        54 => array(
          'name' => 'MC3-CMO',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        55 => array(
          'name' => 'MC3-COO',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        56 => array(
          'name' => 'MC3-CSPO',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        57 => array(
          'name' => 'MC3-Professional Service Area',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        58 => array(
          'name' => 'Microbiology & Immunology',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        59 => array(
          'name' => 'M_AIDS Research Institute',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        60 => array(
          'name' => 'M_Anatomy',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        61 => array(
          'name' => 'M_Anesthesia',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        62 => array(
          'name' => 'M_Anthro, History, Social Med',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        63 => array(
          'name' => 'M_Biochemistry and Biophysics',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        64 => array(
          'name' => 'M_Cardiovascular Research Inst',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        65 => array(
          'name' => 'M_CMP (Cellular Molecular Pha)',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        66 => array(
          'name' => 'M_CTSI',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        67 => array(
          'name' => 'M_Dean\'s Office',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        68 => array(
          'name' => 'M_Dermatology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        69 => array(
          'name' => 'M_Diabetes Center',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        70 => array(
          'name' => 'M_Emergency Medicine',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        71 => array(
          'name' => 'M_Epidemiology & Biostatistics',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        72 => array(
          'name' => 'M_Family Community Medicine',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        73 => array(
          'name' => 'M_HDF Comprehensive Cancer Ctr',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        74 => array(
          'name' => 'M_Howard Hughes Medical Instit',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        75 => array(
          'name' => 'M_IHPS (Health Policy Studies)',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        76 => array(
          'name' => 'M_IND (Neurodegenerative Dis)',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        77 => array(
          'name' => 'M_Laboratory Medicine',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        78 => array(
          'name' => 'M_MEDICINE',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        79 => array(
          'name' => 'M_Microbiology and Immunology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        80 => array(
          'name' => 'M_Neurological Surgery',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        81 => array(
          'name' => 'M_Neurology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        82 => array(
          'name' => 'M_ObGyn, Reproductive Sciences',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        83 => array(
          'name' => 'M_Ophthalmology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        84 => array(
          'name' => 'M_Orthopaedic Surgery',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        85 => array(
          'name' => 'M_Osher Center',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        86 => array(
          'name' => 'M_Otolaryngology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        87 => array(
          'name' => 'M_Pathology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        88 => array(
          'name' => 'M_PEDIATRICS',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        89 => array(
          'name' => 'M_Physical Therapy',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        90 => array(
          'name' => 'M_Physiology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        91 => array(
          'name' => 'M_Psychiatry',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        92 => array(
          'name' => 'M_Radiation Oncology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        93 => array(
          'name' => 'M_Radiology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        94 => array(
          'name' => 'M_Surgery',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        95 => array(
          'name' => 'M_Urology',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        96 => array(
          'name' => 'Neurosurgery Research',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        97 => array(
          'name' => 'News Services',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        98 => array(
          'name' => 'N_Community Health Systems',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        99 => array(
          'name' => 'N_Dean\'s Office',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        100 => array(
          'name' => 'N_Family Health Care Nursing',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        101 => array(
          'name' => 'N_Institute for Health Aging',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        102 => array(
          'name' => 'N_Physiological Nursing',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        103 => array(
          'name' => 'N_Social Behavioral Sciences',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        104 => array(
          'name' => 'Obstetrics, Gynecology & Rep Sci',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        105 => array(
          'name' => 'Orofacial Sciences',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        106 => array(
          'name' => 'Osher Center Integrative Med',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        107 => array(
          'name' => 'Otolaryngology-Head&Neck Surg',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        108 => array(
          'name' => 'Pharmacology',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        109 => array(
          'name' => 'Physical Therapy and Rehab Sci',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        110 => array(
          'name' => 'Preventive/Restore Dental Sci',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        111 => array(
          'name' => 'P_Bioengineering',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        112 => array(
          'name' => 'P_Clinical Pharmacy',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        113 => array(
          'name' => 'P_Dean\'s Office',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        114 => array(
          'name' => 'P_Pharmaceutical Chemistry',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        115 => array(
          'name' => 'Radiology & Biomedical Imaging',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        116 => array(
          'name' => 'Research Resource Program',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        117 => array(
          'name' => 'rp other dept ctsi',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        118 => array(
          'name' => 'RRP',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        119 => array(
          'name' => 'S/d dean-cntr for health prof',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        120 => array(
          'name' => 'S/M-Institute of Global Health',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        121 => array(
          'name' => 'UC Merced',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        122 => array(
          'name' => 'UCSF Global Gealth Sciences',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        123 => array(
          'name' => 'UCSF Human Resources',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        124 => array(
          'name' => 'Univ Community Partnership Prg',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        125 => array(
          'name' => 'Univ Relations Central Office',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        126 => array(
          'name' => 'VC Diversity & Outreach',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        127 => array(
          'name' => 'VC Finance',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        128 => array(
          'name' => 'V_Development',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        129 => array(
          'name' => 'Web Communications',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        130 => array(
          'name' => 'xxx',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        131 => array(
          'name' => 'Academic Senate',
          'description' => '',
          'weight' => '1',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        132 => array(
          'name' => 'Affirmative Action',
          'description' => '',
          'weight' => '2',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        133 => array(
          'name' => 'AIDS Research Institute',
          'description' => '',
          'weight' => '3',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        134 => array(
          'name' => 'Anatomy',
          'description' => '',
          'weight' => '4',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        135 => array(
          'name' => 'Anesthesia/Perioperative Care',
          'description' => '',
          'weight' => '5',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        136 => array(
          'name' => 'Assistant Vice Chancellor - Budget/Finance',
          'description' => '',
          'weight' => '6',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        137 => array(
          'name' => 'Assistant Vice Chancellor - Facilities Management',
          'description' => '',
          'weight' => '7',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        138 => array(
          'name' => 'Associate Dean - SFGH',
          'description' => '',
          'weight' => '8',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        139 => array(
          'name' => 'Associate Vice Chancellor - Administration',
          'description' => '',
          'weight' => '9',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        140 => array(
          'name' => 'Assoc VC - Research',
          'description' => '',
          'weight' => '10',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        141 => array(
          'name' => 'Audit',
          'description' => '',
          'weight' => '11',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        142 => array(
          'name' => 'Biochemistry & Biophysics',
          'description' => '',
          'weight' => '12',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        143 => array(
          'name' => 'Bioengineering and Therapeutic Sciences',
          'description' => '',
          'weight' => '13',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        144 => array(
          'name' => 'Campus Life Services',
          'description' => '',
          'weight' => '14',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        145 => array(
          'name' => 'Campus Planning',
          'description' => '',
          'weight' => '15',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        146 => array(
          'name' => 'Cardiovascular Research Institute',
          'description' => '',
          'weight' => '16',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        147 => array(
          'name' => 'Cellular & Molecular Pharmacology',
          'description' => '',
          'weight' => '17',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        148 => array(
          'name' => 'Center for Bioentrepreneurship',
          'description' => '',
          'weight' => '18',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        149 => array(
          'name' => 'Center for Health Professions',
          'description' => '',
          'weight' => '19',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        150 => array(
          'name' => 'Chancellor\'s Immediate Office',
          'description' => '',
          'weight' => '20',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        151 => array(
          'name' => 'Clinical Pharmacy',
          'description' => '',
          'weight' => '21',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        152 => array(
          'name' => 'Clinical & Translational Science Institute',
          'description' => '',
          'weight' => '22',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        153 => array(
          'name' => 'Dean\'s Office Affiliates',
          'description' => '',
          'weight' => '23',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        154 => array(
          'name' => 'Dental Clinics',
          'description' => '',
          'weight' => '24',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        155 => array(
          'name' => 'Department of Cell & Tissue Biology',
          'description' => '',
          'weight' => '25',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        156 => array(
          'name' => 'Department of Emergency Medicine',
          'description' => '',
          'weight' => '26',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        157 => array(
          'name' => 'Department of Orofacial Sciences',
          'description' => '',
          'weight' => '27',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        158 => array(
          'name' => 'Dermatology',
          'description' => '',
          'weight' => '28',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        159 => array(
          'name' => 'Development',
          'description' => '',
          'weight' => '29',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        160 => array(
          'name' => 'Diabetes Center',
          'description' => '',
          'weight' => '30',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        161 => array(
          'name' => 'Diversity and Outreach',
          'description' => '',
          'weight' => '31',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        162 => array(
          'name' => 'Epidemiology & Biostatistics',
          'description' => '',
          'weight' => '32',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        163 => array(
          'name' => 'Executive Vice Chancellor',
          'description' => '',
          'weight' => '33',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        164 => array(
          'name' => 'Family & Community Medicine',
          'description' => '',
          'weight' => '34',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        165 => array(
          'name' => 'Family Health Care Nursing',
          'description' => '',
          'weight' => '35',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        166 => array(
          'name' => 'Fas Department',
          'description' => '',
          'weight' => '36',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        167 => array(
          'name' => 'FAS Immediate Office',
          'description' => '',
          'weight' => '37',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        168 => array(
          'name' => 'Graduate Division',
          'description' => '',
          'weight' => '38',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        169 => array(
          'name' => 'HDF Comprehensive Cancer Center',
          'description' => '',
          'weight' => '39',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        170 => array(
          'name' => 'History of Health Sciences',
          'description' => '',
          'weight' => '40',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        171 => array(
          'name' => 'Hooper Foundation',
          'description' => '',
          'weight' => '41',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        172 => array(
          'name' => 'Inst for Regeneration Medicine',
          'description' => '',
          'weight' => '42',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        173 => array(
          'name' => 'Inst for Regeneration Nedicine',
          'description' => '',
          'weight' => '43',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        174 => array(
          'name' => 'Institute for Health & Aging',
          'description' => '',
          'weight' => '44',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        175 => array(
          'name' => 'Institute for Health Policy Studies',
          'description' => '',
          'weight' => '45',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        176 => array(
          'name' => 'Institute for Human Genetics',
          'description' => '',
          'weight' => '46',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        177 => array(
          'name' => 'Institute for Neurodegenerative Disease',
          'description' => '',
          'weight' => '47',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        178 => array(
          'name' => 'Institute of Global Health',
          'description' => '',
          'weight' => '48',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        179 => array(
          'name' => 'Ita',
          'description' => '',
          'weight' => '49',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        180 => array(
          'name' => 'Lab of Radiobiology & Env Health',
          'description' => '',
          'weight' => '50',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        181 => array(
          'name' => 'Laboratory Medicine',
          'description' => '',
          'weight' => '51',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        182 => array(
          'name' => 'Library',
          'description' => '',
          'weight' => '52',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        183 => array(
          'name' => 'LPPI: Instruction & Research',
          'description' => '',
          'weight' => '53',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        184 => array(
          'name' => 'Medical Center',
          'description' => '',
          'weight' => '54',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        185 => array(
          'name' => 'Medical Center-CFO',
          'description' => '',
          'weight' => '55',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        186 => array(
          'name' => 'Medical Center-CIO',
          'description' => '',
          'weight' => '56',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        187 => array(
          'name' => 'Medical Center-CMO',
          'description' => '',
          'weight' => '57',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        188 => array(
          'name' => 'Medical Center-COO',
          'description' => '',
          'weight' => '58',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        189 => array(
          'name' => 'Medical Center-CSPO',
          'description' => '',
          'weight' => '59',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        190 => array(
          'name' => 'Medical Center-Moffit/Long Consolidation',
          'description' => '',
          'weight' => '60',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        191 => array(
          'name' => 'Medical Center-Professional Service Area',
          'description' => '',
          'weight' => '61',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        192 => array(
          'name' => 'Medical Center-Sullivan Departments',
          'description' => '',
          'weight' => '62',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        193 => array(
          'name' => 'Medical Education Program',
          'description' => '',
          'weight' => '63',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        194 => array(
          'name' => 'Medicine',
          'description' => '',
          'weight' => '64',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        195 => array(
          'name' => 'Microbiology and Immunology',
          'description' => '',
          'weight' => '65',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        196 => array(
          'name' => 'Neurological Surgery',
          'description' => '',
          'weight' => '66',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        197 => array(
          'name' => 'Neurology',
          'description' => '',
          'weight' => '67',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        198 => array(
          'name' => 'OAAIS',
          'description' => '',
          'weight' => '68',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        199 => array(
          'name' => 'Ob/Gyn & Reproductive Sciences',
          'description' => '',
          'weight' => '69',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        200 => array(
          'name' => 'Office of Ethics & Compliance',
          'description' => '',
          'weight' => '70',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        201 => array(
          'name' => 'Office of Legal Affairs',
          'description' => '',
          'weight' => '71',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        202 => array(
          'name' => 'Office of Sponsored Research',
          'description' => '',
          'weight' => '72',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        203 => array(
          'name' => 'Office of Technology Management',
          'description' => '',
          'weight' => '73',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        204 => array(
          'name' => 'Ophthalmology',
          'description' => '',
          'weight' => '74',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        205 => array(
          'name' => 'Oral & Maxillofacial Surgery',
          'description' => '',
          'weight' => '75',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        206 => array(
          'name' => 'Orthopaedic Surgery',
          'description' => '',
          'weight' => '76',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        207 => array(
          'name' => 'Osher Center for Integrative Medicine',
          'description' => '',
          'weight' => '77',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        208 => array(
          'name' => 'Other',
          'description' => '',
          'weight' => '78',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        209 => array(
          'name' => 'Other Administrative Unit',
          'description' => '',
          'weight' => '79',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        210 => array(
          'name' => 'Otolaryngology',
          'description' => '',
          'weight' => '80',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        211 => array(
          'name' => 'Pathology',
          'description' => '',
          'weight' => '81',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        212 => array(
          'name' => 'Pediatrics',
          'description' => '',
          'weight' => '82',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        213 => array(
          'name' => 'Pharmaceutical Chemistry',
          'description' => '',
          'weight' => '83',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        214 => array(
          'name' => 'Physical Therapy & Rehab Sciences',
          'description' => '',
          'weight' => '84',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        215 => array(
          'name' => 'Physiological Nursing',
          'description' => '',
          'weight' => '85',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        216 => array(
          'name' => 'Physiology',
          'description' => '',
          'weight' => '86',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        217 => array(
          'name' => 'Preventive & Restorative Dental Sci.',
          'description' => '',
          'weight' => '87',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        218 => array(
          'name' => 'Preventive & Restorative Dental Sciences',
          'description' => '',
          'weight' => '88',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        219 => array(
          'name' => 'Proctor Foundation',
          'description' => '',
          'weight' => '89',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        220 => array(
          'name' => 'Psychiatry',
          'description' => '',
          'weight' => '90',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        221 => array(
          'name' => 'QB3 Institute',
          'description' => '',
          'weight' => '91',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        222 => array(
          'name' => 'Radiation Oncology',
          'description' => '',
          'weight' => '92',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        223 => array(
          'name' => 'Radiology',
          'description' => '',
          'weight' => '93',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        224 => array(
          'name' => 'Radiology and Biomedical Imaging',
          'description' => '',
          'weight' => '94',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        225 => array(
          'name' => 'Real Estate Services',
          'description' => '',
          'weight' => '95',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        226 => array(
          'name' => 'Research',
          'description' => '',
          'weight' => '96',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        227 => array(
          'name' => 'School of Dentistry Dean\'s Office',
          'description' => '',
          'weight' => '97',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        228 => array(
          'name' => 'School of Medicine Dean\'s Office',
          'description' => '',
          'weight' => '98',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        229 => array(
          'name' => 'School of Nursing Community Health Systems',
          'description' => '',
          'weight' => '99',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        230 => array(
          'name' => 'School of Nursing Dean\'s Office',
          'description' => '',
          'weight' => '100',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        231 => array(
          'name' => 'School Of Pharmacy - BTS',
          'description' => '',
          'weight' => '101',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        232 => array(
          'name' => 'School of Pharmacy Dean\'s Office',
          'description' => '',
          'weight' => '102',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        233 => array(
          'name' => 'Service Immediate Office',
          'description' => '',
          'weight' => '103',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        234 => array(
          'name' => 'S/M-Osher Ctr Integrative Med',
          'description' => '',
          'weight' => '104',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        235 => array(
          'name' => 'Social & Behavioral Sciences',
          'description' => '',
          'weight' => '105',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        236 => array(
          'name' => 'Student Academic Affairs',
          'description' => '',
          'weight' => '106',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        237 => array(
          'name' => 'Surgery',
          'description' => '',
          'weight' => '107',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        238 => array(
          'name' => 'UCSF Ctr for Hlth & Community',
          'description' => '',
          'weight' => '108',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        239 => array(
          'name' => 'UCSF Global Health Sciences',
          'description' => '',
          'weight' => '109',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        240 => array(
          'name' => 'Univ Advancement & Planning',
          'description' => '',
          'weight' => '110',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        241 => array(
          'name' => 'University Relations',
          'description' => '',
          'weight' => '111',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        242 => array(
          'name' => 'Urology',
          'description' => '',
          'weight' => '112',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
      ),
      'defaults' => array(),
    ),
    'schools' => array(
      'terms' => array(
        0 => array(
          'name' => '',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        1 => array(
          'name' => 'Chancellor/EVC/FAS',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        2 => array(
          'name' => 'Development & Alumni Relations',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        3 => array(
          'name' => 'D_School of Dentistry',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        4 => array(
          'name' => 'Executive vice chancellor',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        5 => array(
          'name' => 'E_Executive Vice Chancellor',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        6 => array(
          'name' => 'Faculty Practice Organization',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        7 => array(
          'name' => 'Financial & Admin Services',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        8 => array(
          'name' => 'F_Finance & Administration',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        9 => array(
          'name' => 'Mc2-medical center(control pt)',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        10 => array(
          'name' => 'Medical Center Main',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        11 => array(
          'name' => 'M_School of Medicine',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        12 => array(
          'name' => 'N_School of Nursing',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        13 => array(
          'name' => 'Other/None',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        14 => array(
          'name' => 'P_School of Pharmacy',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        15 => array(
          'name' => 'School Of Dentistry',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        16 => array(
          'name' => 'School of medicine',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        17 => array(
          'name' => 'School of nursing',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        18 => array(
          'name' => 'School of pharmacy',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        19 => array(
          'name' => 'UC Merced',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        20 => array(
          'name' => 'University Relations',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        21 => array(
          'name' => 'VC Diversity & Outreach',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        22 => array(
          'name' => 'V_Development',
          'description' => NULL,
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        23 => array(
          'name' => 'Dentistry',
          'description' => '',
          'weight' => '1',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        24 => array(
          'name' => 'Medicine',
          'description' => '',
          'weight' => '2',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        25 => array(
          'name' => 'Nursing',
          'description' => '',
          'weight' => '3',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        26 => array(
          'name' => 'Pharmacy',
          'description' => '',
          'weight' => '4',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        27 => array(
          'name' => 'Other',
          'description' => '',
          'weight' => '5',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
      ),
      'defaults' => array(),
    ),
  );
  $export['op_deploy_op_terms_op_user_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_user_pattern';
  $strongarm->value = 'account/[user:name]';
  $export['pathauto_user_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'realname_pattern';
  $strongarm->value = '[user:field_first_name] [user:field_last_name]';
  $export['realname_pattern'] = $strongarm;

  return $export;
}
